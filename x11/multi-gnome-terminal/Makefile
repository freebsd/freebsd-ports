# New ports collection makefile for:   multi-gnome-terminal
# Date created:		19 March 2002
# Whom:		 	Frederic Dubuy <fdubuy@free.fr>
#
# $FreeBSD$
#    $MCom: ports/x11/multi-gnome-terminal/Makefile,v 1.1 2006/10/04 20:27:01 ahze Exp $

PORTNAME=	multi-gnome-terminal
PORTVERSION=	1.6.2
PORTREVISION=	4
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	multignometerm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome tabbed terminal emulator

INSTALLS_OMF=	yes
USE_GNOME=	gnomehack gnomeprefix libglade
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		mgt-helper.1 multi-gnome-terminal.1

post-patch:
	@${REINPLACE_CMD} -e 's|NO_XALF ||' ${WRKSRC}/gnome-terminal/multi-gnome-terminal.desktop

post-install:
	${INSTALL_DATA} ${WRKSRC}/pixmaps/multignometerm.png \
		${PREFIX}/share/gnome/pixmaps/multignometerm.png

.include <bsd.port.mk>
