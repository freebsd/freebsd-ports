# New ports collection makefile for:	fluxbox-devel
# Date created:				21 May 2003
# Whom:					hendrik@scholz.net
#
# $FreeBSD$
#

PORTNAME=	fluxbox
PORTVERSION=	0.9.6
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fluxbox
PKGNAMESUFFIX=	-devel

MAINTAINER=	hendrik@scholz.net
COMMENT=	A small and fast window manager based on BlackBox

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/Xft
RUN_DEPENDS=	bsetbg:${PORTSDIR}/x11-wm/boxtools \
		xterm:${PORTSDIR}/x11/XFree86-4-clients
BUILD_DEPENDS=	xterm:${PORTSDIR}/x11/XFree86-4-clients

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
WANT_GNOME=	yes
USE_REINPLACE=	yes
CONFIGURE_ARGS=		--enable-nls --program-suffix=-devel

.if defined(WITH_KDE) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-kde
.endif

.if defined(WITH_XINERAMA) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

.include <bsd.port.pre.mk>

MAN1=		fluxbox-devel.1

.if ${HAVE_GNOME:Mgnomelibs}!="" || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--enable-gnome
.else
CONFIGURE_ARGS+=	--disable-gnome
.endif

NLSMAKEFILES=	nls nls/C nls/da_DK nls/es_ES nls/et_EE nls/fr_FR nls/pt_BR \
				nls/ru_RU nls/sv_SE nls/tr_TR nls/pt_PT nls/bg_BG nls/ja_JP \
				nls/lv_LV nls/it_IT nls/de_DE

pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "Definable build options"
	@${ECHO_CMD} "-----------------------"
.if !defined(WITH_XINERAMA)
	@${ECHO_CMD} "WITH_XINERAMA	- Enable Xinerama support"
.endif
.if !defined(WITH_KDE)
	@${ECHO_CMD} "WITH_KDE	- Enable KDE slit support"
.endif

post-patch::
	@${REINPLACE_CMD} -e 's|PACKAGE=fluxbox|PACKAGE=fluxbox-devel|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/data/startup.in
	@${REINPLACE_CMD} -e 's|fluxbox-generate_menu|fluxbox-generate_menu-devel|g; \
		s|fbrun|fbrun-devel|g; s|%%LOCALBASE%%|${LOCALBASE}|g; s|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/util/fluxbox-generate_menu.in

post-configure::
.for i in ${NLSMAKEFILES}
	@${REINPLACE_CMD} -e 's|@NLS@|-DNLS|' ${WRKSRC}/${i}/Makefile
.endfor

post-install::
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
