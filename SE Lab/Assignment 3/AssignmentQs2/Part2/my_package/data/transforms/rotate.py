from PIL import Image
import PIL


class RotateImage(object):

    def __init__(self, degrees):
        self.deg = degrees

    def __call__(self, image):
        my_img = Image.fromarray(image)
        new_img = my_img.rotate(self.deg, PIL.Image.NEAREST, expand=1)
        return new_img
