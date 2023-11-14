public class NpuInfo {
    private String name;
    private String address;
    private String telephone;
    
    // 私有静态变量，用于存储唯一实例
    private static NpuInfo instance;
    
    // 私有构造方法，仅可内部创建实例
    private NpuInfo() {
        name = "西北工业大学";
        address = "西安市友谊西路127号";
        telephone = "029-88494433";
    }
    
    // 获取唯一实例
    public static NpuInfo getInstance() {
        if (instance == null) {
            instance = new NpuInfo();
        }
        return instance;
    }
    
    // 公共getter方法
    public String getName() {
        return name;
    }
    
    public String getAddress() {
        return address;
    }
    
    public String getTelephone() {
        return telephone;
    }
}

public class Main {
    public static void main(String[] args) {
        NpuInfo npuInfo = NpuInfo.getInstance();
        System.out.println("学校名称: " + npuInfo.getName());
        System.out.println("地址: " + npuInfo.getAddress());
        System.out.println("联系电话: " + npuInfo.getTelephone());
    }
}
