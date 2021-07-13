from numpy import asarray, max
from PIL import Image
import jsonlines


class Dataset(object):

    def __init__(self, annotation_file, transforms=None):
        self.transforms = transforms
        self.annotation_file = annotation_file
        self.annotation_file = './data/annotations.jsonl'
        self.data = []

        with jsonlines.open(annotation_file, 'r') as f:
            for line in f.iter():
               self.data.append(line)

    def __len__(self):
        return len(self.data)

    def __getitem__(self, idx):                     # modify this function to accommodate for roll no
        if idx in range(0, len(self)):
            filepath = self.data[idx]['img_fn']
            my_img = Image.open(filepath)
            new_img = my_img

            result = {
                'gt_bbox': []
            }

            for boxes in self.data[idx]['bboxes']:
                check = []
                check.append(boxes['category'])
                for coord in boxes['bbox']:
                    check.append(coord)
                result['gt_bbox'].append(check)

            if len(self.transforms) != 0:
                for process in self.transforms:
                    new_img = process(asarray(my_img))

            my_arr = asarray(new_img)
            result['imgarr'] = asarray(new_img)
            my_arr = my_arr / (max(my_arr))
            my_arr = my_arr.transpose(2, 0, 1)
            result['image'] = my_arr
            return result
        else:
            print("Index is out of range!")
