# New ports collection makefile for:    xscreensaver
# Version required:     2.17
# Date created:         10 July 1995
# Whom:                 asami
#
# $Id: Makefile,v 1.9 1998/06/07 01:21:35 asami Exp $
#

DISTNAME=	xscreensaver-2.17
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	jseger@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-shadow --without-motif
USE_X11=	yes
MAN1=		attraction.1 blitspin.1 bouboule.1 braid.1 bubbles.1 \
		decayscreen.1 deco.1 drift.1 flag.1 flame.1 forest.1 \
		galaxy.1 goop.1 grav.1 greynetic.1 halo.1 helix.1 \
		hopalong.1 hypercube.1 ifs.1 imsmap.1 jigsaw.1 julia.1  \
		kaleidescope.1 laser.1 lightning.1 lisa.1 lmorph.1 maze.1 \
		moire.1 munch.1 noseguy.1 pedal.1 penrose.1 pyro.1 qix.1 \
		rd-bomb.1 rocks.1 rorschach.1 sierpinski.1 slidescreen.1 \
		slip.1 sphere.1 spiral.1 starfish.1 strange.1 swirl.1 vines.1 \
		xjack.1 xlyap.1 xroger.1 xscreensaver-command.1 xscreensaver.1

.include <bsd.port.mk>
