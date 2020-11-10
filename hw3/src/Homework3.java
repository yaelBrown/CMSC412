public class Homework3 {
    public static void main(String[] args) {
        for (int i = 0; i < 5; i++) {
            String iteration = String.valueOf(i + 1);

            NewThread nt1 = new NewThread(iteration);
            NewThread nt2 = new NewThread(iteration);
            NewThread nt3 = new NewThread(iteration);

            nt1.run();
            nt2.run();
            nt3.run();
        }
    }
}

class NewThread implements Runnable {
    String n;
    Thread t;

    NewThread(String t_name) {
        n = t_name;
        t = new Thread(this, t_name);
    }

    public void run() {
        try {
            System.out.println("Thread " + t.getId() + " - iteration no. " + n + "\n");
            Thread.sleep(50);
        } catch (InterruptedException e) {
            System.out.println(n + " Interrupted: " + e);
        }
    }
}
