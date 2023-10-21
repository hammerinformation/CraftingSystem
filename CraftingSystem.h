#pragma once
#include <algorithm>
#include <bitset>
#include <concepts>
#include <vector>
#include <array>

template <std::unsigned_integral T = unsigned short, std::size_t MaxItemCount = 8>
class CraftingSystem
{
    std::vector<std::pair<T, std::vector<std::pair<T, T>>>> Conditions;
    std::pair<std::bitset<MaxItemCount>, std::array<T, MaxItemCount>> Items;

public:
    CraftingSystem() noexcept = default;

    void AddItem(const T Item) noexcept
    {
        Items.first.set(Item);
        Items.second[Item] += 1;
    }

    void AddItem(const T Item, const T Count) noexcept
    {
        Items.first.set(Item);
        Items.second[Item] += Count;
    }

    void AddItem(const std::initializer_list<T>& ItemList) noexcept
    {
        for (const auto& Item : ItemList)
        {
            AddItem(Item);
        }
    }

    void AddItem(const std::initializer_list<std::pair<T, T>>& ItemList) noexcept
    {
        for (const auto& Item : ItemList)
        {
            AddItem(Item.first, Item.second);
        }
    }

    void RemoveItem(const T Item) noexcept
    {
        if (Items.second[Item] > 0)
        {
            Items.first.reset(Item);
            Items.second[Item] -= 1;
        }
    }

    void RemoveItem(const T Item, const T Count) noexcept
    {
        if (Items.second[Item] >= Count)
        {
            Items.first.reset(Item);
            Items.second[Item] -= Count;
        }
    }

    void AddConditions(const T Item, const std::vector<std::pair<T, T>> ConditionList) noexcept
    {
        Conditions.push_back({Item, ConditionList});
    }

    template <class CastType=T>
    [[nodiscard]]
    CastType GetItemCount(const T Item) const noexcept
    {
        return static_cast<CastType>(Items.second[Item]);
    }

    [[nodiscard]]
    bool CanCraft(const T Item) const noexcept
    {
        for (const auto& Cond : Conditions)
        {
            if (Cond.first == Item)
            {
                return std::ranges::all_of(Cond.second, [&](const auto& Val)
                {
                    return (GetItemCount(Val.first) >= Val.second);
                });
            }
        }

        return false;
    }
};
