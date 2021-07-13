from PIL import Image
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle


def plot_boxes(imgarr, title, pred_box, pred_class, name, output=None):

    my_img = Image.fromarray(imgarr)
    plt.imshow(my_img)
    plt.title(title)

    n = min(5, len(pred_box))
    for i in range(n):
        plt.text(pred_box[i][0][0], pred_box[i][0][1]+15, pred_class[i], color="red")
        h = pred_box[i][1][0]-pred_box[i][0][0]
        w = pred_box[i][1][1]-pred_box[i][0][1]
        plt.gca().add_patch(Rectangle(pred_box[i][0], h, w, edgecolor="red", lw=0.5, fill=0))

    if output is not None:
        plt.savefig(str(output + "/" + name), dpi=100)

    plt.close()
