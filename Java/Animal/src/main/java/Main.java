public class Main {
    public static void main(String[] args) {
        // 创建狗对象
        Dog dog = new Dog("小狗", 7);
        System.out.println(dog.getName() + ", " + dog.getAge());
        dog.eat();
        dog.swim();
        System.out.println();

        // 创建青蛙对象
        Frog frog = new Frog("小青", 3);
        System.out.println(frog.getName() + ", " + frog.getAge());
        frog.eat();
        frog.swim();
        System.out.println();

        // 创建兔子对象
        Rabbit rabbit = new Rabbit("小兔", 1);
        System.out.println(rabbit.getName() + ", " + rabbit.getAge());
        rabbit.eat();
        System.out.println();
    }
}
