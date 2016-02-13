//
//  ViewController.swift
//  WeatherBroadcast
//
//  Created by Tian Qiu on 7/28/15.
//  Copyright (c) 2015 Tian Qiu. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var TextView: UITextView!
    @IBAction func btnWeatherClick(sender: AnyObject) {
        loadWeather()
        println("Button Clicked")
    }
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        loadWeather()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func loadWeather(){
        
        // Load API
        var url = NSURL(string: "http://www.weather.com.cn/adat/sk/101200101.html")
        var data = NSData(contentsOfURL: url!, options: NSDataReadingOptions(), error: nil)
        var str = NSString(data: data!, encoding: NSUTF8StringEncoding)
        
        var json: AnyObject? = NSJSONSerialization.JSONObjectWithData(data!, options: NSJSONReadingOptions(), error: nil)
        
        var weatherInfo: AnyObject? = json?.objectForKey("weatherinfo")
        var city: AnyObject? = weatherInfo?.objectForKey("city")
        var temp: AnyObject? = weatherInfo?.objectForKey("temp")
        var wind: AnyObject? = weatherInfo?.objectForKey("WD")

        
        TextView.text = " City: \(city) \n Temp: \(temp)\n Wind: \(wind)\n "
    }

}

