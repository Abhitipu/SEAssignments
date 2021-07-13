## Dataset Format

Images are present in ``` imgs ``` folder.

``` annotations.jsonl ``` contains the annotations for the images. The format of the annotations are:

```
{
    "img_fn": 
    "bboxes": [ {
            "category":
            "category_id":
            "bbox" : [x_min y_min x_max y_max]
        }
        .
        .
    ]
}
```

A sample of 10 images with their annotations are given. But at test time, the data will be different (the format will be the same so it will not affect the code)
