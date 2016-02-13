//: Playground - noun: a place where people can play

import Cocoa


var url = NSURL(string: "http://www.weather.com.cn/adat/sk/101200101.html")
var data = NSData(contentsOfURL: url!, options: NSDataReadingOptions(), error: nil)
var str = NSString(data: data!, encoding: NSUTF8StringEncoding)

var json: AnyObject? = NSJSONSerialization.JSONObjectWithData(data!, options: NSJSONReadingOptions(), error: nil)

var weatherInfo: AnyObject? = json?.objectForKey("weatherinfo")
var city: AnyObject? = weatherInfo?.objectForKey("city")
var temp = weatherInfo?.objectForKey("temp")
var wind: AnyObject? = weatherInfo?.objectForKey("WD")






