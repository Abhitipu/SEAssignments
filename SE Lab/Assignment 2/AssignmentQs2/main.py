#Imports
from my_package.model import ObjectDetectionModel
from my_package.data import Dataset
from my_package.analysis import show_boxes
from my_package.data.transforms import FlipImage, RescaleImage, BlurImage, CropImage, RotateImage

def experiment(annotation_file, detector, transforms, outputs):
    '''
        Function to perform the desired experiments

        Arguments:
        annotation_file: Path to annotation file
        detector: The object detector
        transforms: List of transformation classes
        outputs: path of the output folder to store the images
    '''

    #Create the instance of the dataset.
    

    #Iterate over all data items.
    

    #Get the predictions from the detector.
    

    #Draw the boxes on the image and save them.


    #Do the required analysis experiments.
    


def main():
    detector = ObjectDetectionModel()
    experiment('./data/annotations.jsonl', detector, [FlipImage(), BlurImage()], None) # Sample arguments to call experiment()



if __name__ == '__main__':
    main()