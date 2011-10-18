# New ports collection makefile for:	xfce4-clipman-plugin
# Date created:		23 November 2003
# Whom:			Matt Lancereau <matt@rimasec.net>
#
# $FreeBSD$
#

PORTNAME=	xfce4-clipman-plugin
PORTVERSION=	1.1.3
PORTREVISION=	8
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=/src/panel-plugins/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	XFce 4 clipboard module for xfce4-panel

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS=	UNIQUE	"Enable Unique (single instance) support" on

#BROKEN=		Does not work with xfce 4.8

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv libexo libgui libutil panel
USE_XORG=	x11 ice sm xpm

INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_UNIQUE)
LIB_DEPENDS+=	unique-1:${PORTSDIR}/x11-toolkits/unique
CONFIGURE_ARGS+=	--enable-unique
.else
CONFIGURE_ARGS+=	--disable-unique
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|exo-0\.3|exo-1|g; \
		s|thunarx-1|thunarx-2|g' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
