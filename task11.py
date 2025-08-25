import cv2
import numpy as np

image = cv2.imread("test2.jpg")
cv2.imshow("original", image)
cv2.waitKey(0)

gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)  # перевел в оттенки серого
cv2.imshow("gray", gray)
cv2.waitKey(0)

_, thresh = cv2.threshold(gray, 240, 255, cv2.THRESH_BINARY_INV)   # бинаризация
cv2.imshow("thresh", thresh)
cv2.waitKey(0)

contours, _ = cv2.findContours(thresh, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)  # нахожу контуры
contours_areas = [(cv2.contourArea(contour), contour) for contour in contours]  # кортежи(пары) площадь=контур
contours_areas.sort() # сортирую

if contours_areas:
    _, largest_contour = contours_areas[-1]

    x, y, w, h = cv2.boundingRect(largest_contour)
    cx = int(x + w / 2) # int так как cv2.circle не работает с float
    cy = int(y + h / 2)

    result = image.copy()

    cv2.drawContours(result, [largest_contour], -1, (0, 0, 255), 2) # передаю image и массив точек который нужно отрисовать, также цвет контура и толщина
    cv2.circle(result, (cx, cy), 5, (0, 0, 255), -1)

    cv2.imshow("Result", result)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
else:
    print("Фигуры не найдены")

