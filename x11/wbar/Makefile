# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wbar
PORTVERSION=	2.3.4
PORTREVISION=	0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	quick launch bar for fluxbox, WindowMaker, Xfce, etc

LICENSE=	GPLv3

CONFIGURE_ARGS=	--exec-prefix=${PREFIX}

USES=		pkgconfig gettext gmake
USE_EFL=	imlib2

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	NLS WBARCONFIG
OPTIONS_DEFAULT=	NLS WBARCONFIG
OPTIONS_SUB=	yes

WBARCONFIG_DESC=	Build the GTK+ configuration interface

NLS_CONFIGURE_ENABLE=	nls
NLS_CONFIGURE_ENV=	LIBS=-lintl

WBARCONFIG_CONFIGURE_ENABLE=	wbar-config
WBARCONFIG_USE=		GNOME=libglade2

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/wbar.d/wbar.desktop ${STAGEDIR}${DESKTOPDIR}/wbar.desktop

.include <bsd.port.mk>
