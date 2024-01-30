package ObserverPattern.Observer;

import ObserverPattern.Observable.StockObservable;

public class MobileAlertObserverImpl implements NotificationAlertObserver {
    String username;
    StockObservable observable;

    public MobileAlertObserverImpl(String username, StockObservable observable){//constructor injection
        this.observable=observable;
        this.username=username;
    }
    @Override
    public void update(){
        sendMsgOnMobile(username,"Product is in stock Hurry up !!!!");
    }

    private void sendMsgOnMobile(String username,String msg){
        System.out.println("mail sent to:"+username);
        //send the message to user
    }
}