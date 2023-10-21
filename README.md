# C++20 CraftingSystem 
This is a C++ class template for a crafting system that allows you to manage items and add crafting conditions.

## Example

```cpp
namespace Item
{
    enum Type:unsigned char
    {
        Iron = 0,
        Wood = 1,
        Stone = 2,
        Water = 3,
        Hammer = 4
    };
}

int main()
{
    cout << boolalpha;
    CraftingSystem craftingSystem;
    craftingSystem.AddItem(Item::Wood);
    craftingSystem.AddItem(Item::Wood, 5);
    craftingSystem.AddItem(Item::Wood, 10);
    craftingSystem.AddItem({Item::Wood, Item::Iron});
    craftingSystem.AddItem({{Item::Wood, 13}, {Item::Iron, 20}});
    craftingSystem.RemoveItem(Item::Wood, 4);
    craftingSystem.RemoveItem(Item::Wood);
    craftingSystem.AddConditions(Item::Hammer, {{Item::Iron, 2,}, {Item::Stone, 5}, {Item::Wood, 10}});
    cout << craftingSystem.GetItemCount(Item::Wood) << "\n"; // 25
    cout << craftingSystem.CanCraft(Item::Hammer) << "\n"; //false
    craftingSystem.AddItem(Item::Stone, 5);
    cout << craftingSystem.CanCraft(Item::Hammer) << "\n"; //true

    return 0;
}


```


## Add Item
These four AddItem functions allow for the addition of items to the crafting system. They can add a single item, a specified quantity of an item, a list of items, or a list of item-quantity pairs. Each function handles the addition process efficiently.

```cpp
    CraftingSystem craftingSystem;
    craftingSystem.AddItem(Item::Wood);
    craftingSystem.AddItem(Item::Wood, 5);
    craftingSystem.AddItem(Item::Wood, 10);
    craftingSystem.AddItem({Item::Wood, Item::Iron});
    craftingSystem.AddItem({{Item::Wood, 15}, {Item::Iron, 20}});

```

## Add Conditions
This line of code sets up crafting conditions for creating a "Hammer" in the crafting system, specifying that 2 units of "Iron," 5 units of "Stone," and 10 units of "Wood" are required for crafting. If these conditions are not met, crafting the "Hammer" will not be possible.
```cpp

    craftingSystem.AddConditions(Item::Hammer, {{Item::Iron, 2,}, {Item::Stone, 5}, {Item::Wood, 10}});

``` 
## Remove Item 
```cpp

    CraftingSystem craftingSystem;
    craftingSystem.AddItem(Item::Wood,5);
    craftingSystem.RemoveItem(Item::Wood,3); //2
    craftingSystem.RemoveItem(Item::Wood); //1
    cout<<craftingSystem.GetItemCount(Item::Wood); //1

```




