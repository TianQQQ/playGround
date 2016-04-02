from django.db import models

# Create your models here.

from django.db import models

class Person(models.Model):            # person has name and age
    name = models.CharField(max_length=30)
    age = models.IntegerField()

    def __str__(self):     # return 从object 改成 person's name
        return self.name