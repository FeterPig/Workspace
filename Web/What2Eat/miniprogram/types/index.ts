// 定义一个接口，相当于 struct FoodItem
export interface FoodItem {
  id: number; // 时间戳做 ID
  name: string; // 菜名
  weight: number; // 权重 (1-10)
  canteen?: string; // (可选) 食堂位置
}
