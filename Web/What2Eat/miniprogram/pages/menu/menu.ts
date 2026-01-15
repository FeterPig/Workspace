// 1. 引入必要的类型定义 (就像 C++ include 头文件)
// 如果没用到 FoodItem 可以删掉这行
import { FoodItem } from "../../types/index";
import { getFoodList, saveFoodList } from "../../utils/storage";

Component({
  /**
   * 1. 属性列表 (Properties)
   * 类似于 C++ 构造函数的参数
   * 只有当这个组件被别人调用，且传参进来时才用。
   * 做独立页面时，这里通常是空的。
   */
  properties: {
    // 示例: title: { type: String, value: '' }
  },

  /**
   * 2. 组件的初始数据 (Data)
   * 类似于 C++ 类里的 Private Member Variables
   * 注意：只有这里定义的数据，才能在 WXML 里用 {{}} 绑定
   */
  data: {
    // 显式断言类型，否则 TS 可能会把它推断成 never[]
    foodList: [] as FoodItem[],
    isLoading: false,
    inputValue: "",
  },

  /**
   * 3. 方法列表 (Methods)
   * 类似于 C++ 类里的 Public Member Functions
   * 注意：页面生命周期 (onShow, onLoad) 和 点击事件 都要写在这里面！
   */
  methods: {
    // ------------------- 生命周期区 -------------------

    /**
     * 对应 Page 的 onLoad
     * 页面刚加载时触发 (只触发一次)
     */
    onLoad() {
      console.log("页面加载了...");
    },

    /**
     * 对应 Page 的 onShow
     * 每次切回这个页面都会触发
     * 适合在这里刷新数据 (Refresh)
     */
    onShow() {
      this.refreshData();
    },

    // ------------------- 业务逻辑区 -------------------

    // 封装一个刷新数据的私有函数
    refreshData() {
      const list = getFoodList();
      this.setData({ foodList: list });
    },

    // ------------------- 事件处理区 -------------------

    // TODO: 点击按钮的事件
    onMyButtonClick(e: any) {
      console.log("按钮被点了", e);
      // 逻辑写在这里
    },

    // TODO: 输入框输入事件
    onInputChange(e: any) {
      this.setData({
        inputValue: e.detail.value,
      });
    },
  },
});
