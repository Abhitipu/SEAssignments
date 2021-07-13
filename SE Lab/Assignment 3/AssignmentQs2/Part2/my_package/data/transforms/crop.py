from PIL import Image
import random


class CropImage(object):

    def __init__(self, shape, crop_type='Center'):

        self.h, self.w = shape      # (h, w)
        self.crop_type = crop_type

    def __call__(self, image):
        my_img = Image.fromarray(image)
        h, w = my_img.size

        if self.crop_type == 'Center':
            top = (h-self.h) // 2
            bottom = top + self.h
            left = (w-self.w) // 2
            right = left + self.w
        else:
            top = random.randint(0, h-self.h)
            left = random.randint(0, w-self.w)
            bottom = top + self.h
            right = left + self.w

        new_img = my_img.crop((left, top, right, bottom))
        return new_img
