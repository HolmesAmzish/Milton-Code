import cv2
import numpy as np

# Read the image
image = cv2.imread("poker.jpg")
# Convert the image to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Define the template region
template = gray[75:105, 235:265]

# Match the template
match = cv2.matchTemplate(gray, template, cv2.TM_CCOEFF_NORMED)
locations = np.where(match >= 0.9)

# Get the dimensions of the template
h, w = template.shape[0:2]

# Draw rectangles around matched regions
for p in zip(*locations[::-1]):
    x1, y1 = p[0], p[1]
    x2, y2 = x1 + w, y1 + h
    cv2.rectangle(image, (x1, y1), (x2, y2), (0, 255, 0), 2)

# Display the result
cv2.imshow("image", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
