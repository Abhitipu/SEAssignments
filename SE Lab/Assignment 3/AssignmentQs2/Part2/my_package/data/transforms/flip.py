from PIL import Image


class FlipImage(object):

    def __init__(self, flip_type='horizontal'):
        self.flip_type = flip_type
        
    def __call__(self, image):
        my_img = Image.fromarray(image)
        if self.flip_type == 'horizontal':
            new_img = my_img.transpose(Image.FLIP_LEFT_RIGHT)
        else:
            new_img = my_img.transpose(Image.FLIP_TOP_BOTTOM)

        return new_img
