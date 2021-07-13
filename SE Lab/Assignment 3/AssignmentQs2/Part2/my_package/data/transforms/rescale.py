from PIL import Image


class RescaleImage(object):

    def __init__(self, output_size, scale=False):
        self.output_size = output_size
        self.scale = scale

    def __call__(self, image=(0, 0)):
        my_img = Image.fromarray(image)

        if self.scale:
            w, h = my_img.size
            w *= self.output_size
            h *= self.output_size
            new_img = my_img.resize((int(w), int(h)), Image.ANTIALIAS)

        elif isinstance(self.output_size, int):
            w, h = my_img.size
            if w < h:
                h = h*self.output_size // w
                w = self.output_size
            else:
                w = w * self.output_size // h
                h = self.output_size
            new_img = my_img.resize((int(w), int(h)), Image.ANTIALIAS)
        else:
            new_img = my_img.resize(self.output_size, Image.ANTIALIAS)

        return new_img