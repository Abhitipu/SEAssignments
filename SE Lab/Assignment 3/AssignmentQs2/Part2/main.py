# Abhinandan De
# 19CS10069

import my_package

from my_package import ObjectDetectionModel
from my_package.data import Dataset
from my_package.analysis import plot_boxes
from my_package.data.transforms import FlipImage, RescaleImage, BlurImage, CropImage, RotateImage


def experiment(annotation_file, detector, transforms, outputs):

    my_data = Dataset(annotation_file, [])

    my_arr = []
    for i in range(len(my_data)):
        check = my_data[i]
        my_arr.append(check)        # this has the data in the form of the required dictionary!
        pred_boxes, pred_class, pred_score = detector(check['image'])
        plot_boxes(check['imgarr'], "Image " + str(i) + str(" plot boxes"), pred_boxes, pred_class, str(i) + "_edited_pt1.png", outputs)
        print("Plotted for image " + str(i))

    my_roll_no = 9
    req = [[transform[0]] for transform in transforms]
    req.append([])

    i = 0
    for transform in req:
        my_data.transforms = transform
        check = my_data[my_roll_no]
        pred_boxes, pred_class, pred_score = detector(check['image'])
        if len(req[i]) != 0:
            s = transforms[i][1]
            i += 1
        else:
            s = str("No transform")
        print(s)
        plot_boxes(check['imgarr'], s, pred_boxes, pred_class, str(my_roll_no) + "_" + s + "_edited_pt2.png", outputs)


def main():
    detector = ObjectDetectionModel()
    
    transforms = [
        (FlipImage('horizontal'), str("Flipped image horizontally")),
        (BlurImage(1), str("Blurred image")),
        (RescaleImage(2, True), str("Rescaled image 2x")),
        (RescaleImage(0.5, True), str("Rescaled image 0.5x")),
        (RotateImage(-90), str("Rotated image by 90deg right")),
        (RotateImage(45), str("Rotated image by 45deg left"))
    ]

    experiment('./data/annotations.jsonl', detector, transforms, "./saved")


if __name__ == '__main__':
    main()