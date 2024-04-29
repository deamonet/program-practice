import java.io.File;
import java.io.IOException;

public class FileIOTest {
        public static void main(String[] args) throws IOException {
            File f = File.createTempFile("tmp-", ".txt"); // 提供临时文件的前缀和后缀
            f.deleteOnExit(); // JVM退出时自动删除
            System.out.println(f.isFile());
            System.out.println(f.getAbsolutePath());
        }
}
