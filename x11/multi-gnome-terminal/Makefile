# New ports collection makefile for:   multi-gnome-terminal
# Date created:		19 March 2002
# Whom:		 	Frederic Dubuy <fdubuy@free.fr>
#
# $FreeBSD$
#

PORTNAME=	multi-gnome-terminal
PORTVERSION=	1.5.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://multignometerm.sourceforge.net/
MASTER_SITE_SUBDIR=	multignometerm

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
