# New ports collection makefile for:   multi-gnome-terminal
# Date created:		19 March 2002
# Whom:		 	Frederic Dubuy <fdubuy@free.fr>
#
# $FreeBSD$
#

PORTNAME=	multi-gnome-terminal
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://multignometerm.sourceforge.net/
MASTER_SITE_SUBDIR=	multignometerm

MAINTAINER=	fdubuy@free.fr
COMMENT=	Gnome tabbed terminal emulator

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack gnomecanvas libglade
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

MAN1=		multi-gnome-terminal.1

post-install:
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/multignometerm.png \
		${PREFIX}/share/gnome/pixmaps/multignometerm.png

.include <bsd.port.mk>
