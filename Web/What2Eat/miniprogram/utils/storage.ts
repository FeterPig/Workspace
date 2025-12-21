import { FoodItem } from "../types/index";

const KEY = "WHAT2EAT_FOOD_LIST";

// 获取列表
export function getFoodList(): FoodItem[] {
    // 从本地存储拿，拿不到就返回空数组
    return wx.getStorageSync(KEY) || [];
}

// 保存列表
export function saveFoodList(list: FoodItem[]): void {
    wx.setStorageSync(KEY, list);
}

// 初始化一些默认数据 (给新用户用的)
export function initDefaultData() {
    const current = getFoodList();
    if (current.length === 0) {
        const defaults: FoodItem[] = [
            { id: 1, name: "黄焖鸡", weight: 1 },
            { id: 2, name: "麻辣烫", weight: 1 },
            { id: 3, name: "二楼自助", weight: 1 }
        ];
        saveFoodList(defaults);
    }
}