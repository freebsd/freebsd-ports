# New ports collection makefile for:   multi-gnome-terminal
# Date created:		19 March 2002
# Whom:		 	Frederic Dubuy <fdubuy@free.fr>
#
# $FreeBSD$
#

PORTNAME=	multi-gnome-terminal
PORTVERSION=	1.4.1
CATEGORIES=	x11 gnome
MASTER_SITES=	http://telia.dl.sourceforge.net/sourceforge/multignometerm/ \
		http://unc.dl.sourceforge.net/sourceforge/multignometerm/ \
		http://belnet.dl.sourceforge.net/sourceforge/multignometerm/ \
		http://multignometerm.sourceforge.net/

MAINTAINER=	fdubuy@free.fr

BUILD_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper
LIB_DEPENDS+=	xml.5:${PORTSDIR}/textproc/libxml \
		ORBit.2:${PORTSDIR}/devel/ORBit
RUN_DEPENDS=	scrollkeeper-config:${PORTSDIR}/textproc/scrollkeeper

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_GNOME=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
# The distribution Makefile.in files append "/gnome" to --datadir
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share

MAN1=		multi-gnome-terminal.1

.include <bsd.port.mk>
