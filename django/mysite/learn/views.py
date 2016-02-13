from django.shortcuts import render
from django.http import HttpResponse

#coding:utf-8
# create view here

def index(request):
	return HttpResponse(u"欢迎光临 first test for add calculation")

def add(request):             # /add/?a=4&b=5 
	a = request.GET.get('a', 0)
	b = request.GET.get('b', 0) # 当没有a传递时， a默认为0
	c = int(a)+int(b)
	return HttpResponse('we can get a+b = ' + str(c))

def add2(request, a, b):       #  /add/3/4/ 
	c = int(a) + int(b)
	return HttpResponse(str(c))
