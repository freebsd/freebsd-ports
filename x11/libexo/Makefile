# New ports collection makefile for:	libexo
# Date created:		23 October 2004
# Whom:			Matt Lancereau <ports@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11/libexo/Makefile,v 1.1 2006/10/02 21:05:55 ahze Exp $

PORTNAME=	libexo
PORTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	x11 xfce
DISTNAME=	exo-${PORTVERSION}
MASTER_SITES=	${MASTER_SITES_XFCE}

DIST_SUBDIR=	xfce4
PATCH_SITES=	http://people.freebsd.org/~oliver/xfce/
PATCHFILES=	gcc295-libexo.patch

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Terminal library, extensions to Xfce by os-cillation

BUILD_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${DISTNAME}

GNU_CONFIGURE=	yes
INSTALLS_ICONS= yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack gnometarget gtk20 intltool intlhack pkgconfig
USE_LDCONFIG=	yes
USE_XFCE=	configenv libutil mcsmanager
USE_XLIB=	yes

OPTIONS=	HAL	"Enable HAL support"			on \
		NOTIFY  "Enable notification support"		on \
		PYTHON	"Enable Python support"			off \
		GTKDOC	"Build with documentation"		off \
		MCS	"Build with xfce4-mcs-manager support"	on

MAN1=		exo-csource.1 exo-open.1

.include <bsd.port.pre.mk>

.if defined(WITH_GTKDOC)
BUILD_DEPENDS+=	gtkdocize:${PORTSDIR}/textproc/gtk-doc
CONFIGURE_ARGS+=--enable-gtk-doc
PLIST_SUB+=	GTK_DOC=""
.else
CONFIGURE_ARGS+=--disable-gtk-doc
PLIST_SUB+=	GTK_DOC="@comment "
.endif

.if !defined(WITHOUT_HAL)
CONFIGURE_ARGS+=--enable-hal
LIB_DEPENDS+=	hal.1:${PORTSDIR}/sysutils/hal
.else
CONFIGURE_ARGS+=--disable-hal
.endif

.if !defined(WITHOUT_NOTIFY)
CONFIGURE_ARGS+=--enable-notifications
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
PLIST_SUB+=	NOTIFY=""
.else
CONFIGURE_ARGS+=--disable-notifications
PLIST_SUB+=	NOTIFY="@comment "
.endif

.if defined(WITH_PYTHON)
CONFIGURE_ARGS+=--enable-python
USE_PYTHON=	yes
.include "${PORTSDIR}/Mk/bsd.python.mk"
BUILD_DEPENDS+=	${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pygtk.py:${PORTSDIR}/x11-toolkits/py-gtk2
PLIST_SUB+=	PYTHON=""
.else
CONFIGURE_ARGS+=--disable-python
PLIST_SUB+=	PYTHON="@comment "
.endif

.if !defined(WITHOUT_MCS)
CONFIGURE_ARGS+=--enable-mcs-plugin
BUILD_DEPENDS+=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager
RUN_DEPENDS+=	xfce-mcs-manager:${PORTSDIR}/sysutils/xfce4-mcs-manager
PLIST_SUB+=	MCS_MANAGER=""
.else
CONFIGURE_ARGS+=--disable-mcs-plugin
PLIST_SUB+=	MCS_MANAGER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|FALSE;;|FALSE;|' ${WRKSRC}/exo/exo-icon-view.c
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
