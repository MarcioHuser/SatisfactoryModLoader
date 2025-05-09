// Copyright Coffee Stain Studios. All Rights Reserved.

#pragma once

#include "FactoryGame.h"
#include "FGInventoryComponent.h"
#include "ItemAmount.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FGInventoryLibrary.generated.h"


/**
 * Function library to provide the glue between c++ and the inventory in blueprint so we can handle inventory items with a state easy in blueprint.
 */
UCLASS()
class FACTORYGAME_API UFGInventoryLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	/** Manual break for inventory stack. */
	UFUNCTION( BlueprintPure, Category = "Inventory" )
	static void BreakInventoryStack( UPARAM( ref ) const FInventoryStack& stack,
									 UPARAM( DisplayName = "Num Items" ) int32& out_numItems,
									 UPARAM( DisplayName = "Item" ) FInventoryItem& out_item );

	/** Manual break for inventory item. */
	UFUNCTION( BlueprintPure, Category = "Inventory" )
	static void BreakInventoryItem( UPARAM( ref ) const FInventoryItem& item,
									UPARAM( DisplayName = "Class" ) TSubclassOf< class UFGItemDescriptor >& out_itemClass,
									UPARAM( DisplayName = "State" ) FFGDynamicStruct& out_itemState );

	/** Manual make for inventory item. */
	UFUNCTION( BlueprintPure, Category = "Inventory" )
	static FInventoryItem MakeInventoryItem( UPARAM( DisplayName = "Class" ) TSubclassOf< class UFGItemDescriptor > itemClass );

	/** Creates inventory item with the provided item state */
	UFUNCTION( BlueprintPure, Category = "Inventory" )
	static FInventoryItem MakeInventoryItemWithState( UPARAM( DisplayName = "Class" ) TSubclassOf< class UFGItemDescriptor > itemClass, const FFGDynamicStruct& itemState );

	/** Manual make for inventory stack. */
	UFUNCTION( BlueprintPure, Category = "Inventory" )
	static FInventoryStack MakeInventoryStack( int32 numItems, FInventoryItem item );

	/** @return true if the inventory item is a valid item; otherwise false. */
	UFUNCTION( BlueprintPure, Category = "Inventory" )
	static FORCEINLINE bool IsValidItem( UPARAM( ref ) const FInventoryItem& item ) { return item.IsValid(); }

	/** @return true if this inventory item has a state; otherwise false. */
	UFUNCTION( BlueprintPure, Category = "Inventory" )
	static FORCEINLINE bool HasState( UPARAM( ref ) const FInventoryItem& item ) { return item.HasState(); }

	/** Returns the amount of inventory items converted to the appropriate units for displaying in the UI
	* @param amount - quantity of unmodified inventory items. eg. 1000 Liquid inventory will be divided by 1000.f to return 1 m^3
	*/
	UFUNCTION( BlueprintPure, Category = "Inventory" )
	static float GetAmountConvertedByForm( int32 amount, EResourceForm form );

	/** Returns the UI Suffix for production quantities based on a Resource Form Type */
	UFUNCTION( BlueprintPure, Category = "Inventory" )
	static FText GetProductionSuffixFromFormType( EResourceForm form );

	UFUNCTION( BlueprintPure, Category = "Inventory" )
	static float GetConversionScalarByForm( EResourceForm form );

	/** Returns the amount of inventory items converted to the appropriate units for displaying in the UI. Also returns the split itemAmount for ease of access in widgets.
	* @param itemAmount - FItemAmount to use as the base for conversion. The item form will be pulled from the itemAmount.ItemClass to determine the conversion.
	* @param itemClass - (Out) The item class of the FItemAmount
	* @param amountConverted - The amount converted to the correct representation in the UI. eg. 1000 Liquid inventory will be divided by 1000.f to return 1.f ( m^3 )
	*/
	UFUNCTION( BlueprintPure, Category = "Item" )
	static void GetAmountConvertedFromItemAmount( UPARAM( ref ) const FItemAmount& itemAmount, TSubclassOf< class UFGItemDescriptor >& itemClass, float& amountConverted );

	/** Returns the amount of stack items converted to the appropriate units for displaying in the UI, excluding suffix and form data. This also returns the split data for ease of access in Widgets.
	* @param inventoryStack - (In) FInventoryStack to use as the base for conversion. The item form will be pulled from the stacks ItemClass to determine the conversion.
	* @param buildableClass - (In) (Optional) if passed a valid buildable and the resource form is not SOLID, the converted maximimum stack will also be scaled by the buildables stack size
	* @param itemClass - (Out) The item class of the inventory stack.
	* @param numItemsConverted - (Out) The numItems converted to the correct representation for the UI. eg. 1000 Liquid inventory will be divided by 1000.f to return 1.f ( m^3 )
	* @param maxItemsConverted - (Out) The max stack size for this InventoryStack. If a buildableClass was passed and the resource form is not SOLID, this value will also be scaled to by the buildables stack size scalar.
	*/
	UFUNCTION( BlueprintPure, Category = "Item" )
	static void GetUIDataPartialForInventoryStack( UPARAM( ref ) const FInventoryStack& inventoryStack, const TSubclassOf< class AFGBuildableFactory > buildableFactory, TSubclassOf< class UFGItemDescriptor>& itemClass, float& numItemsConverted, float& maxItemsConverted );

	/** Returns the amount of stack items converted to the appropriate units for displaying in the UI including suffix and form data. This also returns the split data for ease of access in Widgets.
	* @param inventoryStack - (In) FInventoryStack to use as the base for conversion. The item form will be pulled from the stacks ItemClass to determine the conversion.
	* @param buildableClass - (In) (Optional) if passed a valid buildable and the resource form is not SOLID, the converted maximimum stack will also be scaled by the buildables stack size
	* @param itemClass - (Out) The item class of the inventory stack.
	* @param numItemsConverted - (Out) The numItems converted to the correct representation for the UI. eg. 1000 Liquid inventory will be divided by 1000.f to return 1.f ( m^3 )
	* @param maxItemsConverted - (Out) The max stack size for this InventoryStack. If a buildableClass was passed and the resource form is not SOLID, this value will also be scaled to by the buildables stack size scalar.
	* @param suffix - (Out) The UI suffix for this part form ( Tex. Solid = "Parts", Liquid = "m^3" )
	* @param form - (Out) The resource form of this ItemStack
	*/
	UFUNCTION( BlueprintPure, Category = "Item" )
	static void GetUIDataFullForInventoryStack( UPARAM( ref ) const FInventoryStack& inventoryStack, const TSubclassOf< class AFGBuildableFactory > buildableFactory, TSubclassOf< class UFGItemDescriptor>& itemClass, float& numItemsConverted, float& maxItemsConverted, FText& suffix, EResourceForm& form );
	
	/** @return a none item. */
	static FORCEINLINE FInventoryItem GetNullInventoryItem() { return FInventoryItem::NullInventoryItem; }

	/** @return true if the stack has any items; false if the stack is empty. */
	UFUNCTION( BlueprintPure, Category = "Inventory" )
	static FORCEINLINE bool HasItems( UPARAM( ref ) const FInventoryStack& stack ) { return stack.HasItems(); }

	/**
	 * This is a UI helper function for drag n drop that automagically moves or swaps items.
	 * It moves or swaps an item from a one location to another location. Verifying that the move or swap is allowed.
	 * @note Server only
	 *
	 * @return true on success; false if something goes wrong during the move.
	 */
	//@todoinventory RENAME Stack
	UFUNCTION( BlueprintCallable, Category = "Inventory" )
	static bool MoveInventoryItem( UFGInventoryComponent* sourceComponent, const int32 sourceIdx, UFGInventoryComponent* destinationComponent, const int32 destinationIdx );

	/**
	* Tries to grab all items in the source and add them to the dest. I can't decide what optimal grabbing is, so this is just the easiest implementation.
	* @note Server only
	*
	* @return true on success; false if something goes wrong during the move.
	*/
	UFUNCTION( BlueprintCallable, Category = "Inventory" )
	static bool GrabAllItemsFromInventory( UFGInventoryComponent* sourceComponent, UFGInventoryComponent* destinationComponent, TSubclassOf< UFGItemDescriptor > onlyGrabOfDesc = nullptr );

	/**
	 * Helper to consolidate the given items into as few items as possible.
	 * E.g. consolidate this:    50 iron, 50 iron, 30 copper, 35 iron
	 *      into this:           135 iron, 30 copper
	 *
	 * @note This do not apply any stacking limits.
	 */
	//@todoinventory RENAME Stacks
	UFUNCTION( BlueprintCallable, Category = "Inventory" )
	static void ConsolidateInventoryItems( UPARAM( ref ) TArray< FInventoryStack >& items );

	/**
	* Calculates how many inventory slots the passed number of items requires.
	*
	* ASSUMES CONSOLIDATED ARRAY
	*/
	UFUNCTION( BlueprintCallable, Category = "Inventory" )
	static int32 GetMinNumSlotsForItems( UPARAM( ref ) TArray< FInventoryStack >& items );

	/**
	 * Helper to merge an inventory item into an array of other inventory items.
	 *
	 * @param items - Merge item into this array.
	 * @param item - This is the item to merge into the items array.
	 *
	 * @note This do not apply any stacking limits.
	 */
	//@todoinventory RENAME Stack
	UFUNCTION( BlueprintCallable, Category = "Inventory" )
	static void MergeInventoryItem( UPARAM( ref ) TArray< FInventoryStack >& items, const FInventoryStack& item );

	/**
	* Helper to consolidate the given items into as few items as possible.
	* E.g. consolidate this:    50 iron, 50 iron, 30 copper, 35 iron
	*      into this:           135 iron, 30 copper
	*
	* @note This do not apply any stacking limits.
	*/
	UFUNCTION( BlueprintCallable, Category = "Inventory" )
	static void ConsolidateItemsAmount( UPARAM( ref ) TArray< FItemAmount >& items );


	/** 
	* Removes all stacks whom's resource form does not match the passed form
	* @param items - Array of items by ref to remove from
	* @param validForm - Keep items of this form. Default == RF_SOLID
	*/
	UFUNCTION( BlueprintCallable, Category = "Inventory" )
	static void RemoveAllItemsNotOfResourceForm( UPARAM( ref ) TArray< FInventoryStack >& items, EResourceForm validForm = EResourceForm::RF_SOLID );

	/** 
	* Removes the number of items of the given item class from the inventory component and the central storage subsystem.
	* @param inventoryComponent - The inventory to grab from
	* @param centralStorageSubsystem - The central storage to grab from
	* @param takeFromInventoryBeforeCentralStorage - Decides from where to take items first
	* @param itemClass - The item class to remove
	* @param numItemsToRemove - Number of items of item class to remove
	*/
	static void GrabItemsFromInventoryAndCentralStorage( class UFGInventoryComponent* inventoryComponent, class AFGCentralStorageSubsystem* centralStorageSubsystem,
		bool takeFromInventoryBeforeCentralStorage, TSubclassOf< class UFGItemDescriptor> itemClass, int32 numItemsToRemove );

	/**
	 * Grabs the given amount of the specified item from the central storage and moves it to the specific inventory's slot
	 * If there is not enough item in the central storage, or the slot cannot fit all of the items, it will grab as many as possible up to the specified amount
	 * @param itemAmount type and amount of item to grab
	 * @param destinationComponent inventory component to move the item into
	 * @param destinationIdx index of the destination inventory slot
	 * @return number of items actually grabbed into the slot
	 */
	UFUNCTION( BlueprintCallable, Category = "Inventory" )
	static int32 GrabItemFromCentralStorage( const FItemAmount& itemAmount, UFGInventoryComponent* destinationComponent, const int32 destinationIdx );

	/**
	 * Moves the given amount of item from the central storage into the given inventory component.
	 * If there is not enough items in the central storage, or the inventory cannot fit all of the items, it will move as many items as possible
	 * @param itemAmount type and amount of item to move
	 * @param destinationComponent inventory component to move the item into
	 * @return number of items actually moved into the inventory
	 */
	UFUNCTION( BlueprintCallable, Category = "Inventory" )
	static int32 MoveItemFromCentralStorage( const FItemAmount& itemAmount, UFGInventoryComponent* destinationComponent );

	/** Removes all inventory contents that can be discarded. Leaves item stacks that cannot be discarded intact */
	UFUNCTION( BlueprintCallable, Category = "Inventory" )
	static void DiscardInventoryContents( UFGInventoryComponent* inventoryComponent );

	UFUNCTION( BlueprintPure, Category = "Inventory" )
	static bool IsAutoOpenTooltipEnabled();

	UFUNCTION( BlueprintCallable, Category = "Inventory" )
	static void SetAutoOpenTooltipMenu(bool Enable);

	static bool AutoOpenTooltipMenu;

};