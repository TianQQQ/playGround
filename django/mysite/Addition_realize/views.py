# -*- coding: utf-8 -*-

from django.shortcuts import render
from django.http import HttpResponse


from django.http import HttpResponseRedirect   # for rrdirect
from django.core.urlresolvers import reverse
#coding:utf-8
# create view here

def index(request):
	return HttpResponse(u"welcome first test for add calculation")

def add1(request):             # /add/?a=4&b=5
	a = request.GET.get('a', 0)
	b = request.GET.get('b', 0) # 当没有a传递时， a默认为0
	c = int(a)+int(b)
	return HttpResponse('we can get a+b = ' + str(c))

def add2(request, a, b):       #  /add/3/4/
	c = int(a) + int(b)
	return HttpResponse('From add2 we can get: ' + str(c))


def old_add2_redirect(request, a, b):
    return HttpResponseRedirect(
        reverse('add2', args=(a, b))
    )
