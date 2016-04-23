# coding:utf-8
from django.contrib import admin
from .models import Article, Person

# admin: tianqiu password: a
# 进入 blog 文件夹，修改 admin.py 文件（如果没有新建一个），内容如下

# admin.site.register(Article)

# 1.定制加载的列表, 根据不同的人显示不同的内容列表，比如输入员只能看见自己输入的，审核员能看到所有的草稿，这时候就需要重写get_queryset方法
class MyModelAdmin(admin.ModelAdmin):
    def get_queryset(self, request):
        qs = super(MyModelAdmin, self).get_queryset(request)
        if request.user.is_superuser:
            return qs
        else:
            return qs.filter(author=request.user)


class ArticleAdmin(admin.ModelAdmin):
    list_display = ('title', 'pub_date', 'update_time',)


class PersonAdmin(admin.ModelAdmin):
    list_display = ('full_name',)

admin.site.register(Article, ArticleAdmin)
admin.site.register(Person, PersonAdmin)