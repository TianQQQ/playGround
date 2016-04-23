# -*- coding: utf-8 -*-
from django.db import models
# Create your models here.

from django.db import models


class Person(models.Model):            # person has name and age
    name = models.CharField(max_length=30)
    age = models.IntegerField()

    def __str__(self):     # return 从object 改成 person's name
        return self.name


class CompressedTextField(models.TextField):
    """    model Fields for storing text in a compressed format (bz2 by default)    """
    __metaclass__ = models.SubfieldBase

    def to_python(self, value):
        if not value:
            return value

        try:
            return value.decode('base64').decode('bz2').decode('utf-8')
        except Exception:
            return value

    def get_prep_value(self, value):
        if not value:
            return value

        try:
            value.decode('base64')
            return value
        except Exception:
            try:
                tmp = value.encode('utf-8').encode('bz2').encode('base64')
            except Exception:
                return value
            else:
                if len(tmp) > len(value):
                    return value

                return tmp