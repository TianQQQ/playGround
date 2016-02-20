from django.conf.urls import include, url, patterns
from django.contrib import admin
from learn import views as learn_views  # from learn new



urlpatterns = [
    # Examples:
    # url(r'^$', 'mysite.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),

	url(r'^$', learn_views.index),           # from learn new welcome


	url(r'^add1', learn_views.add1, name='add1'),    # add function,
	# name = 'add' means to home/add


	#url(r'^add2/(\d+)/(\d+)/$', learn_views.add2, name='add2'),


	url(r'^add2/(\d+)/(\d+)/$', learn_views.old_add2_redirect),
    url(r'^new_add/(\d+)/(\d+)/$', learn_views.add2, name='add2'),


    url(r'^admin/', include(admin.site.urls)),
]
