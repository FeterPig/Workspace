import { initDefaultData } from "./utils/storage";

// 这里的 <IAppOption> 就是那个“契约”
App<IAppOption>({
  // 1. 补上这个！哪怕是空的也要写，为了满足接口要求
  globalData: {},

  onLaunch() {
    // 初始化数据
    initDefaultData();
    console.log("App Launch: 数据初始化完成");
  },
});
