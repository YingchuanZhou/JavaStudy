package syn;

//账户
class Account{
    int money;//余额
    String name;//卡名

    public Account(int money, String name) {
        this.money = money;
        this.name = name;
    }
}
//银行：模拟取款
class Drawing extends Thread{
    Account account;//账户
    //取了多少钱；
    int drawingMoney;
    //现在手里又多少钱
    int nowMoney;
    public Drawing(Account account,int drawingMoney,String name){
        super(name);
        this.account=account;
        this.drawingMoney=drawingMoney;

    }
    //取钱

    @Override
    public void run() {
        synchronized (account) {//锁的对象是变化的量，锁需要增删改的对象
            //判断有没有钱
            if (account.money - drawingMoney <= 0) {
                System.out.println(Thread.currentThread().getName() + "钱不够");
                return;
            }
            //卡内余额
            account.money -= drawingMoney;
            //手里的钱
            nowMoney += drawingMoney;
            System.out.println(account.name + "余额为:" + account.money);
            System.out.println(this.getName() + "手里的钱:" + nowMoney);
        }
    }
}