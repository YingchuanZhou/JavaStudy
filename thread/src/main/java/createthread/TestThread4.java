package createthread;

import java.util.concurrent.*;

//床技安线程的方式三：实现Callable接口
public class TestThread4 implements Callable<Boolean> {

        public Boolean call() throws Exception {
            System.out.println("创建成功");
            return true;
        }

        public static void main(String[] args) throws ExecutionException, InterruptedException {
            TestThread4 callable = new TestThread4();

            //创建执行服务
            ExecutorService service = Executors.newFixedThreadPool(1);
            //提交执行
            Future<Boolean> result = service.submit(callable);
//          获取结果
            boolean isTrue = result.get();
//           关闭服务
            service.shutdownNow();

        }
}
