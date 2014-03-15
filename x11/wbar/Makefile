# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wbar
PORTVERSION=	2.3.4
PORTREVISION=	0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A quick launch bar for fluxbox, WindowMaker, Xfce, etc

LICENSE=	GPLv3

CONFIGURE_ARGS=	--exec-prefix=${PREFIX}

USES=		pkgconfig

GNU_CONFIGURE=	yes

MAN1=	${PORTNAME}.1
MANLANG=	"" es

OPTIONS_DEFINE=	NLS WBARCONFIG
OPTIONS_DEFAULT=	NLS WBARCONFIG

WBARCONFIG_DESC=	Build the GTK+ configuration interface

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ENV=	LIBS=-lintl
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=	NLS="@comment "
# The configure script has a couple of bugs...
post-patch:
	${REINPLACE_CMD} -e "s,install-data-@USE_NLS@,install-data-no,g" ${WRKSRC}/po/Makefile.in.in
.endif

.if ${PORT_OPTIONS:MWBARCONFIG}
CONFIGURE_ARGS+=	--enable-wbar-config
PLIST_SUB+=	WBARCONFIG=""
MAN1+=	${PORTNAME}-config.1
USE_GNOME=	libglade2
.else
CONFIGURE_ARGS+=	--disable-wbar-config
PLIST_SUB+=	WBARCONFIG="@comment "
.endif

USE_EFL=	imlib2
USES+=		gettext gmake
USE_GNOME+=	desktopfileutils intltool

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB+=	DESKTOPDIR=${DESKTOPDIR:S,${PREFIX}/,,}

post-install:
	${MV} ${PREFIX}/etc/wbar.d/wbar.desktop ${DESKTOPDIR}/wbar.desktop

.include <bsd.port.mk>
