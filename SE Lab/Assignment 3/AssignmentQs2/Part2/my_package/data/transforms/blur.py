from PIL import Image, ImageFilter


class BlurImage(object):   # Applies Gaussian Blur on the image.

    def __init__(self, radius):
        self.radius = radius

    def __call__(self, image):
        my_img = Image.fromarray(image)
        new_img = my_img.filter(ImageFilter.GaussianBlur(radius=self.radius))
        return new_img
