/*
 * 802.1Q VLAN protocol definitions
 *
 * $Copyright Open Cypress Semiconductor$
 *
 * $Id: vlan.h 372455 2012-12-03 22:17:37Z pnemavat $
 */

#ifndef _vlan_h_
#define _vlan_h_

#ifndef _TYPEDEFS_H_
#include <typedefs.h>
#endif

/* This marks the start of a packed structure section. */
#include <packed_section_start.h>

#define VLAN_VID_MASK		0xfff	/* low 12 bits are vlan id */
#define	VLAN_CFI_SHIFT		12	/* canonical format indicator bit */
#define VLAN_PRI_SHIFT		13	/* user priority */

#define VLAN_PRI_MASK		7	/* 3 bits of priority */

#define	VLAN_TAG_LEN		4
#define	VLAN_TAG_OFFSET		(2 * ETHER_ADDR_LEN)	/* offset in Ethernet II packet only */

#define VLAN_TPID		0x8100	/* VLAN ethertype/Tag Protocol ID */

struct ethervlan_header {
	uint8	ether_dhost[ETHER_ADDR_LEN];
	uint8	ether_shost[ETHER_ADDR_LEN];
	uint16	vlan_type;		/* 0x8100 */
	uint16	vlan_tag;		/* priority, cfi and vid */
	uint16	ether_type;
};

struct dot3_mac_llc_snapvlan_header {
	uint8	ether_dhost[ETHER_ADDR_LEN];	/* dest mac */
	uint8	ether_shost[ETHER_ADDR_LEN];	/* src mac */
	uint16	length;				/* frame length incl header */
	uint8	dsap;				/* always 0xAA */
	uint8	ssap;				/* always 0xAA */
	uint8	ctl;				/* always 0x03 */
	uint8	oui[3];				/* RFC1042: 0x00 0x00 0x00
						 * Bridge-Tunnel: 0x00 0x00 0xF8
						 */
	uint16	vlan_type;			/* 0x8100 */
	uint16	vlan_tag;			/* priority, cfi and vid */
	uint16	ether_type;			/* ethertype */
};

#define	ETHERVLAN_HDR_LEN	(ETHER_HDR_LEN + VLAN_TAG_LEN)


/* This marks the end of a packed structure section. */
#include <packed_section_end.h>

#define ETHERVLAN_MOVE_HDR(d, s) \
do { \
	struct ethervlan_header t; \
	t = *(struct ethervlan_header *)(s); \
	*(struct ethervlan_header *)(d) = t; \
} while (0)

#endif /* _vlan_h_ */
