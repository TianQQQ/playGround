/*
    Created by Qiu on 7/6/15
*/

public class alarmClock{
    private int delay;
    private boolean hasSound;
    public alarmClock(int delay, boolean hasSound){
        this.delay = delay;
        this.hasSound = hasSound;
    }
    
    public void start(){
        class Printer implements ActionListener{
            @Override
            public void actionPerformed(ActionEvent e){     // action
                SimpleDateFormat format = new SimpleDateFormat("k:m:s");    // build time format
                String result = format.format(new Date());                  // get current time
                System.out.println("Current time is : " + result);          // show current time
                if(hasSound){
                    Toolkil.getDefaultToolkit().beep();
                }
            }
        }
        
        new Timer(delay, new Printer()).start();             // build timer and start
    }
}