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

#include "Player.h"
#include "Define.h"
#include "Creature.h"
#include "ScriptMgr.h"
#include "WorldSession.h"
#include "ScriptedGossip.h"
#include "Language.h"

class JC_Tools_NPC : public CreatureScript
{
public:
        JC_Tools_NPC() : CreatureScript("JC_Tools_NPC") { }
 
	bool OnGossipHello(Player *player, Creature *creature)
        {
		AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface\\icons\\Spell_Nature_Regenerate:30:30:-15|t Restore Life and Mana", GOSSIP_SENDER_MAIN, 1);
		AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface\\icons\\Spell_Shadow_UnstableAffliction_1:30:30:-15|t Reset Instances", GOSSIP_SENDER_MAIN, 2);
		AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface\\icons\\SPELL_HOLY_BORROWEDTIME:30:30:-15|t Reset Cooldowns", GOSSIP_SENDER_MAIN, 3);
		AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface\\icons\\Achievement_BG_AB_defendflags:30:30:-15|t Reset Combat", GOSSIP_SENDER_MAIN, 4);
		AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface\\icons\\Spell_Shadow_DeathScream:30:30:-15|t Remove Sickness", GOSSIP_SENDER_MAIN, 5);
		AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface\\icons\\INV_Hammer_24:30:30:-15|t Reparar Items", GOSSIP_SENDER_MAIN, 6);
		AddGossipItemFor(player, GOSSIP_ICON_DOT, "|TInterface\\icons\\Achievement_WorldEvent_Lunar:30:30:-15|t Reset Talents", GOSSIP_SENDER_MAIN, 7);
		AddGossipItemFor(player, GOSSIP_ICON_INTERACT_1, "|TInterface\\icons\\Achievement_WorldEvent_Lunar:30:30:-15|t Get out", GOSSIP_SENDER_MAIN, 8);
		SendGossipMenuFor(player, DEFAULT_GOSSIP_MESSAGE, creature->GetGUID());
                return true;
        }
	bool OnGossipSelect(Player *player, Creature *creature, uint32 sender, uint32 action)
        {
                player->PlayerTalkClass->ClearMenus();
                switch(action)
                {
                case 1: // Restaurar HP e MP
                        if(player->IsInCombat())
                        {
                            player->GetSession()->SendNotification("|cffFFFF00JadeCore Servers - Tools \n |cffFFFFFFYou are in combat!");
							player->PlayerTalkClass->SendCloseGossip();
                                return false;
                        }
                        else if(player->getPowerType() == POWER_MANA)
                                player->SetPower(POWER_MANA, player->GetMaxPower(POWER_MANA));
 
							player->SetHealth(player->GetMaxHealth());
							player->GetSession()->SendNotification("|cffFFFF00JadeCore Servers - Tools \n |cffFFFFFFLife and Mana Reset Successfully!");
							player->CastSpell(player, 36400);
							CloseGossipMenuFor(player);
                        break;

                case 2: // Resetar Instances
                        for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
                        {
                                Player::BoundInstancesMap &binds = player->GetBoundInstances(Difficulty(i));
                                for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
                                {
                                        player->UnbindInstance(itr, Difficulty(i));
                                }
                        }
						player->GetSession()->SendNotification("|cffFFFF00JadeCore Servers - Tools \n |cffFFFFFFInstances Reset Successfully!");
						player->CastSpell(player, 59908);
                        CloseGossipMenuFor(player);
                        break;

                case 3: // Resetar Cooldowns
                        if(player->IsInCombat())
                        {
                            player->GetSession()->SendNotification("|cffFFFF00JadeCore Servers - Tools \n |cffFFFFFFYou are in combat!");
							player->PlayerTalkClass->SendCloseGossip();
                                return false;
                        }
 
						player->GetSpellHistory()->ResetAllCooldowns();
						player->GetSession()->SendNotification("|cffFFFF00JadeCore Servers - Tools \n |cffFFFFFFCooldowns Reset Successfully!");
						player->CastSpell(player, 463);
                        CloseGossipMenuFor(player);
                        break;

                case 4: // Resetar Combat
                        player->CombatStop();
						player->GetSession()->SendNotification("|cffFFFF00JadeCore Servers - Tools \n |cffFFFFFFCombat Removed Successfully!");
						player->CastSpell(player, 24222);
                        CloseGossipMenuFor(player);
                        break;

                case 5: // Remover Sickness
                        if(player->HasAura(15007))
                        player->RemoveAura(15007);
						player->GetSession()->SendNotification("|cffFFFF00JadeCore Servers - Tools \n |cffFFFFFFSickness Removed Successfully!");
						player->CastSpell(player, 41300);
                        CloseGossipMenuFor(player);
                        break;

                case 6: // Reparar Items
                        player->DurabilityRepairAll(false, 0, false);
						player->GetSession()->SendNotification("|cffFFFF00JadeCore Servers - Tools \n |cffFFFFFFRepaired Equipment Successfully!");
						player->CastSpell(player, 29541);
                        CloseGossipMenuFor(player);
                        break;

               case 7: // Resetar Talents
                        player->ResetTalents(true);
                        player->SendTalentsInfoData(false);
						player->GetSession()->SendNotification("|cffFFFF00JadeCore Servers - Tools \n |cffFFFFFFReset talents with Success!");
						player->CastSpell(player, 19484);
                        CloseGossipMenuFor(player);
                        break;

				case 8: // Fechar Menu
						player->GetSession()->SendNotification("|cffFFFF00JadeCore Servers - Tools \n |cffFFFFFFThank you, Always use this tool so you need!");
						CloseGossipMenuFor(player);
						break;
             }
                return true;
        }
};
 
void AddSC_JC_Tools_NPC()
{
        new JC_Tools_NPC();
}