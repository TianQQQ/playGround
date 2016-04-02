from django.db import models

# Create your models here.

from django.db import models

class Person(models.Model):            # person has name and age
    name = models.CharField(max_length=30)
    age = models.IntegerField()