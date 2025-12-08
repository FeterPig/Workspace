import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        // 1. 实例化核心服务 (Library 对象)
        Library myLibrary = new Library();

        // 2. 准备用户输入工具
        Scanner scanner = new Scanner(System.in);
        int choice = 0;

        System.out.println("--- 欢迎使用简易图书馆管理系统 ---");

        while (choice != 4) {
            // 打印菜单
            System.out.println("\n请选择操作:");
            System.out.println("1. 添加新书");
            System.out.println("2. 查找图书 (ISBN)");
            System.out.println("3. 借出图书 (进阶)");
            System.out.println("4. 退出系统");
            System.out.print("请输入数字 (1-4): ");

            if (scanner.hasNextInt()) {
                choice = scanner.nextInt();
                scanner.nextLine(); // 消费掉数字后的换行符

                switch (choice) {
                    case 1:
                        addBookInteraction(myLibrary, scanner);
                        break;
                    case 2:
                        findBookInteraction(myLibrary, scanner);
                        break;
                    case 3:
                        System.out.println("\n--- 借出图书 ---");
                        System.out.print("请输入要借出的 ISBN 编号: ");
                        String borrowIsbn = scanner.nextLine();

                        boolean success = myLibrary.borrowBook(borrowIsbn);

                        if (success) {
                            System.out.println("✅ ISBN " + borrowIsbn + " 借出成功！");
                        } else {
                            System.out.println("❌ 操作失败：图书不存在或已被借出。");
                        }
                        break;
                    case 4:
                        System.out.println("感谢使用，系统退出。");
                        break;
                    default:
                        System.out.println("输入无效，请重新输入。");
                }
            } else {
                System.out.println("输入无效，请重新输入数字。");
                scanner.nextLine(); // 清除无效输入
            }
        }
        scanner.close(); // 养成良好习惯，关闭资源
    }

    // --- 业务交互方法（将复杂的输入逻辑封装起来） ---

    public static void addBookInteraction(Library lib, Scanner sc) {
        System.out.println("\n--- 添加新书 ---");
        System.out.print("书名: ");
        String title = sc.nextLine();
        System.out.print("作者: ");
        String author = sc.nextLine();
        System.out.print("ISBN 编号: ");
        String isbn = sc.nextLine();

        // 核心 OOP 步骤 1: 创建对象（调用 Book 类的构造函数）
        // 默认设置为未借出 (false)
        Book newBook = new Book(title, author, isbn, false);

        // 核心 OOP 步骤 2: 调用 Library 服务的业务方法
        lib.addBook(newBook);

        System.out.println("✅ 图书添加成功: " + title);
    }

    public static void findBookInteraction(Library lib, Scanner sc) {
        System.out.println("\n--- 查找图书 ---");
        System.out.print("请输入 ISBN 编号: ");
        String isbn = sc.nextLine();

        // 核心 OOP 步骤 3: 调用 Library 服务的查询方法
        Book foundBook = lib.findBookByISBN(isbn);

        if (foundBook != null) {
            // 核心 OOP 步骤 4: 通过 Getter 访问 Book 对象的属性
            System.out.println("--- 找到图书 ---");
            System.out.println("书名: " + foundBook.getTitle());
            System.out.println("作者: " + foundBook.getAuthor());
            System.out.println("ISBN: " + foundBook.getIsbn());
            System.out.println("是否借出: " + (foundBook.getIsBorrowed() ? "是" : "否"));
        } else {
            System.out.println("❌ 错误：未找到 ISBN 为 " + isbn + " 的图书。");
        }
    }
}