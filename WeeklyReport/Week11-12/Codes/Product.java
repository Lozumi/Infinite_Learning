public class Product {
    // 属性
    private String code;
    private String description;
    private double price;
    private String shelfLife;

    // 构造函数
    public Product(String code, String description, double price, String shelfLife) {
        this.code = code;
        this.description = description;
        this.price = price;
        this.shelfLife = shelfLife;
    }

    // 方法
    public String getCode() {
        return this.code;
    }

    public String getDescription() {
        return this.description;
    }

    public double getPrice() {
        return this.price;
    }

    public String getShelfLife() {
        return this.shelfLife;
    }

    // 添加 toString 方法
    @Override
    public String toString() {
        return "Product{" +
                "code='" + code + '\'' +
                ", description='" + description + '\'' +
                ", price=" + price +
                ", shelfLife='" + shelfLife + '\'' +
                '}';
    }

    public static void main(String[] args) {
        Product ProductOne = new Product("01","酸奶",100,"10");
        System.out.println(ProductOne);
    }
}
