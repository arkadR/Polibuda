import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class IntCell1 {
    private int n = 0;
    public int getN() {

        lock.lock();
        return n;
    }
    public void setN(int n) {
        this.n = n;
        lock.unlock();
    }
    private final Lock lock = new ReentrantLock();
}

class Count1 extends Thread {
    private static IntCell1 n = new IntCell1();
    @Override public void run() {
        int temp;
        for (int i = 0; i < 200000; i++) {
            temp = n.getN();
            n.setN(temp + 1);
        }
    }
    public static void main(String[] args) {
        Count1 p = new Count1();
        Count1 q = new Count1();
        p.start();
        q.start();
        try { p.join(); q.join(); }
        catch (InterruptedException e) { }
        System.out.println("The value of n is " + n.getN());
    }
}
