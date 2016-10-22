/*
 * Copyright (C) 2013-2016 JadeCore <https://www.jadecore.tk/>
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "../../../scripts/ScriptPCH.h"

class weptransmog : public CreatureScript
{
public:
    weptransmog() : CreatureScript("weptransmog") { }

    bool OnGossipHello(Player *player, Creature *_creature)
    {
        if (player->IsInCombat())
        {
            CloseGossipMenuFor(player);
			_creature->Whisper("You are in combat!", LANG_UNIVERSAL, player);
            return true;
        }
        else
        {
			if (player->getClass() == CLASS_ROGUE)  
			{
				AddGossipItemFor(player,  3, "|cff3300FFWarglaive of Azzinoth (Combat, Sublety)"     , GOSSIP_SENDER_MAIN, 100);
				AddGossipItemFor(player,  3, "|cff3300FFWarblade of the Hakkari (Combat, Sublety)"   , GOSSIP_SENDER_MAIN, 101);
				AddGossipItemFor(player,  3, "|cff3300FFGutgore Ripper (Assasin, Sublety)"           , GOSSIP_SENDER_MAIN, 102);
				AddGossipItemFor(player,  3, "|cff3300FFFist of Molten Fury (Combat, Sublety)"       , GOSSIP_SENDER_MAIN, 103);
				AddGossipItemFor(player,  3, "|cff3300FFThunderfury (Combat, Sublety)"               , GOSSIP_SENDER_MAIN, 104);
				AddGossipItemFor(player,  3, "|cff3300FFJaded Crystal Dagger (All Spec)"             , GOSSIP_SENDER_MAIN, 113);
				AddGossipItemFor(player,  3, "|cff3300FFStarshard Edge (All Spec)"                   , GOSSIP_SENDER_MAIN, 117);
			}
			if (player->getClass() == CLASS_PALADIN) 
			{
				AddGossipItemFor(player,  3, "|cff3300FFIce Spire Scepter (Holy)"                     , GOSSIP_SENDER_MAIN, 105);
                AddGossipItemFor(player,  3, "|cff3300FFVal'anyr, Hammer of Ancient Kings (Holy)"     , GOSSIP_SENDER_MAIN, 106);
                AddGossipItemFor(player,  3, "|cff3300FFZin'rokh, Destroyer of Worlds (Retri)"        , GOSSIP_SENDER_MAIN, 107);
                AddGossipItemFor(player,  3, "|cff3300FFHigh Warlord's Greatsword (Retri)"            , GOSSIP_SENDER_MAIN, 108);
                AddGossipItemFor(player,  3, "|cff3300FFGrand Marshal's Claymore (Retri)"             , GOSSIP_SENDER_MAIN, 109);
                AddGossipItemFor(player,  3, "|cff3300FFSulfuras, Hand of Ragnaros (Retri)"           , GOSSIP_SENDER_MAIN, 110);
                AddGossipItemFor(player,  3, "|cff3300FFWarglaive of Azzinoth (Prot)"                 , GOSSIP_SENDER_MAIN, 100);	
                AddGossipItemFor(player,  3, "|cff3300FFThunderfury (Prot)"                           , GOSSIP_SENDER_MAIN, 104);				
			}
			if (player->getClass() == CLASS_WARRIOR) 
			{
                AddGossipItemFor(player,  3, "|cff3300FFZin'rokh, Destroyer of Worlds(Arms/Fury)"        , GOSSIP_SENDER_MAIN, 107);
                AddGossipItemFor(player,  3, "|cff3300FFHigh Warlord's Greatsword(Arms/Fury)"            , GOSSIP_SENDER_MAIN, 108);
                AddGossipItemFor(player,  3, "|cff3300FFGrand Marshal's Claymore(Arms/Fury)"             , GOSSIP_SENDER_MAIN, 109);
                AddGossipItemFor(player,  3, "|cff3300FFSulfuras, Hand of Ragnaros(Arms/Fury)"           , GOSSIP_SENDER_MAIN, 110);	
                AddGossipItemFor(player,  3, "|cff3300FFAshbringer(Arms/Fury)"                           , GOSSIP_SENDER_MAIN, 111);	
                AddGossipItemFor(player,  3, "|cff3300FFDraconic Avenger(Arms/Fury)"                     , GOSSIP_SENDER_MAIN, 112);
                AddGossipItemFor(player,  3, "|cff3300FFWarglaive of Azzinoth (Prot)"                    , GOSSIP_SENDER_MAIN, 100);	
                AddGossipItemFor(player,  3, "|cff3300FFThunderfury (Prot)"                              , GOSSIP_SENDER_MAIN, 104);				
			}
			if (player->getClass() == CLASS_DEATH_KNIGHT) 
			{
				AddGossipItemFor(player,  3, "|cff3300FFZin'rokh, Destroyer of Worlds (Blood/Unholy)"        , GOSSIP_SENDER_MAIN, 107);
                AddGossipItemFor(player,  3, "|cff3300FFHigh Warlord's Greatsword (Blood/Unholy)"            , GOSSIP_SENDER_MAIN, 108);
                AddGossipItemFor(player,  3, "|cff3300FFGrand Marshal's Claymore (Blood/Unholy)"             , GOSSIP_SENDER_MAIN, 109);
                AddGossipItemFor(player,  3, "|cff3300FFSulfuras, Hand of Ragnaros (Blood/Unholy)"           , GOSSIP_SENDER_MAIN, 110);	
                AddGossipItemFor(player,  3, "|cff3300FFAshbringer (Blood/Unholy)"                           , GOSSIP_SENDER_MAIN, 111);	
                AddGossipItemFor(player,  3, "|cff3300FFDraconic Avenger (Blood/Unholy)"                     , GOSSIP_SENDER_MAIN, 112);
                AddGossipItemFor(player,  3, "|cff3300FFWarglaive of Azzinoth (Frost)"                       , GOSSIP_SENDER_MAIN, 100);
                AddGossipItemFor(player,  3, "|cff3300FFThunderfury (Frost)"                                 , GOSSIP_SENDER_MAIN, 104);				
			}
			if (player->getClass() == CLASS_HUNTER) 
			{
				AddGossipItemFor(player,  3, "|cff3300FFSulfuras, Hand of Ragnaros (All Spec)"           , GOSSIP_SENDER_MAIN, 110);
                AddGossipItemFor(player,  3, "|cff3300FFWarglaive of Azzinoth (All Spec)"               , GOSSIP_SENDER_MAIN, 100);
                AddGossipItemFor(player,  3, "|cff3300FFThunderfury (All Spec)"                         , GOSSIP_SENDER_MAIN, 104);
                AddGossipItemFor(player,  3, "|cff3300FFGolden Bow of Quel'Thalas (Bow)"                , GOSSIP_SENDER_MAIN, 114);
                AddGossipItemFor(player,  3, "|cff3300FFArcanite Steam-Pistol (Gun)"                    , GOSSIP_SENDER_MAIN, 115);	
                AddGossipItemFor(player,  3, "|cff3300FFLegionkiller (Crossbow)"                        , GOSSIP_SENDER_MAIN, 116);
				AddGossipItemFor(player,  3, "|cff3300FFHalberd of Smiting (All Spec)"                  , GOSSIP_SENDER_MAIN, 120);
			}
			if (player->getClass() == CLASS_PRIEST) 
			{
				AddGossipItemFor(player,  3, "|cff3300FFJaded Crystal Dagger (All Spec)"                 , GOSSIP_SENDER_MAIN, 113);
                AddGossipItemFor(player,  3, "|cff3300FFStarshard Edge (All Spec)"                       , GOSSIP_SENDER_MAIN, 117);
                AddGossipItemFor(player,  3, "|cff3300FFVal'anyr, Hammer of Ancient Kings (All Spec)"    , GOSSIP_SENDER_MAIN, 106);
				AddGossipItemFor(player,  3, "|cff3300FFWarblade of the Hakkari (All Spec)"              , GOSSIP_SENDER_MAIN, 119);
				AddGossipItemFor(player,  3, "|cff3300FFRoyal Scepter of Terenas (All Spec)"             , GOSSIP_SENDER_MAIN, 118);
			}
			if (player->getClass() == CLASS_MAGE) 
			{
				AddGossipItemFor(player,  3, "|cff3300FFJaded Crystal Dagger (All Spec)"                 , GOSSIP_SENDER_MAIN, 113);
                AddGossipItemFor(player,  3, "|cff3300FFStarshard Edge (All Spec)"                       , GOSSIP_SENDER_MAIN, 117);	
                AddGossipItemFor(player,  3, "|cff3300FFVal'anyr, Hammer of Ancient Kings (All Spec)"    , GOSSIP_SENDER_MAIN, 106);
                AddGossipItemFor(player,  3, "|cff3300FFWarblade of the Hakkari (All Spec)"              , GOSSIP_SENDER_MAIN, 119);				
			}
			if (player->getClass() == CLASS_WARLOCK) 
			{
				AddGossipItemFor(player,  3, "|cff3300FFJaded Crystal Dagger (All Spec)"                 , GOSSIP_SENDER_MAIN, 113);
                AddGossipItemFor(player,  3, "|cff3300FFStarshard Edge (All Spec)"                       , GOSSIP_SENDER_MAIN, 117);	
                AddGossipItemFor(player,  3, "|cff3300FFVal'anyr, Hammer of Ancient Kings (All Spec)"    , GOSSIP_SENDER_MAIN, 106);
                AddGossipItemFor(player,  3, "|cff3300FFRoyal Scepter of Terenas (All Spec)"             , GOSSIP_SENDER_MAIN, 118);
                AddGossipItemFor(player,  3, "|cff3300FFWarblade of the Hakkari (All Spec)"              , GOSSIP_SENDER_MAIN, 119);				
			}
			if (player->getClass() == CLASS_DRUID) 
			{
                AddGossipItemFor(player,  3, "|cff3300FFRoyal Scepter of Terenas (Resto/Ballance)"         , GOSSIP_SENDER_MAIN, 118);
                AddGossipItemFor(player,  3, "|cff3300FFJaded Crystal Dagger (Resto/Ballance)"             , GOSSIP_SENDER_MAIN, 113);
				AddGossipItemFor(player,  3, "|cff3300FFSulfuras, Hand of Ragnaros (Feral)"                , GOSSIP_SENDER_MAIN, 110);
                AddGossipItemFor(player,  3, "|cff3300FFStarshard Edge (Resto/Ballance)"                   , GOSSIP_SENDER_MAIN, 117);
                AddGossipItemFor(player,  3, "|cff3300FFWarblade of the Hakkari (Resto/Ballance)"          , GOSSIP_SENDER_MAIN, 119);
				AddGossipItemFor(player,  3, "|cff3300FFHalberd of Smiting (Feral)"                        , GOSSIP_SENDER_MAIN, 120);
			}
			if (player->getClass() == CLASS_SHAMAN)
			{
				AddGossipItemFor(player,  3, "|cff3300FFRoyal Scepter of Terenas (Ele/Resto)"         , GOSSIP_SENDER_MAIN, 118);
				AddGossipItemFor(player,  3, "|cff3300FFJaded Crystal Dagger (Ele/Resto)"             , GOSSIP_SENDER_MAIN, 113);
				AddGossipItemFor(player,  3, "|cff3300FFStarshard Edge (Ele/Resto)"                   , GOSSIP_SENDER_MAIN, 117);
				AddGossipItemFor(player,  3, "|cff3300FFVal'anyr, Hammer of Ancient Kings (Ele/Resto)" , GOSSIP_SENDER_MAIN, 106);
				AddGossipItemFor(player,  3, "|cff3300FFZin'rokh, Destroyer of Worlds (Enhcant)"        , GOSSIP_SENDER_MAIN, 107);
				AddGossipItemFor(player,  3, "|cff3300FFDraconic Avenger (Enhcant)"                     , GOSSIP_SENDER_MAIN, 112);
			}
	    }

        SendGossipMenuFor(player, 60007, _creature->GetGUID());         
        return true;
    }

    bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 uiAction)
    {
        if (sender == GOSSIP_SENDER_MAIN)
        {
            ClearGossipMenuFor(player);
            switch(uiAction)
            {
			case 999:
			            CloseGossipMenuFor(player);
            _creature->Whisper("Come again, friend!", LANG_UNIVERSAL, player);
			break;
			
      case 100: //Rogue
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 28524); // main hand*/
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 32838); // offhand
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 101:
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 5191); // main hand*/
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19866); // offhand
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 102:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 17071); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19866); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 103:
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 17071); // main hand*/
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 32945); // offhand
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 104:
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 17071); // main hand*/
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 105: // Paladin
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 40488); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 106:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 46017); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 107:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 19854); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 108:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 18877); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 109:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 18876); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 110:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 17182); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 111:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 13262); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 112:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 19354); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 113:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 34604); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 114:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_18_ENTRYID, 34196); // ranged
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 115:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_18_ENTRYID, 29949); // ranged
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 116:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_18_ENTRYID, 32253); // ranged
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 117:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 45620); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 118:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 50428); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  case 119:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 19866); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;

	  case 120:
		  player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID, 19874); // main hand
		  /*player->UpdateUInt32Value(PLAYER_VISIBLE_ITEM_17_ENTRYID, 19019); // offhand*/
		  CloseGossipMenuFor(player);
		  _creature->Whisper("Your items have been successfully modified!", LANG_UNIVERSAL, player);
      break;
	  
	  default:
      break;                   
    }
   }
  return true;
 }
};

void AddSC_weptransmog()
{
    new weptransmog();
}