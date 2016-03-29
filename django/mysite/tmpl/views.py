# -*- coding: utf-8 -*-
from django.shortcuts import render

# Create your views here.

def home1(request):
    return render(request, 'home.html')

def home2(request):
    string = u"这是直接在用string传递的home2"
    return render(request, 'home2.html', {'string': string})


def home3(request):
    TutorialList = ["HTML", "CSS", "jQuery", "Python", "Django"]
    return render(request, 'home3.html', {'TutorialList': TutorialList})

def home4(request):
    List = map(str, range(100))# 一个长度为100的 List
    return render(request, 'home4.html', {'List': List})