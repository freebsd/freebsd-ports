# New ports collection makefile for:	gnomepanel
# Date created:				27 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnomepanel/Makefile,v 1.109 2005/10/08 19:41:40 marcus Exp $
#

PORTNAME=	gnomepanel
PORTVERSION=	2.12.3
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-panel/2.12
DISTNAME=	gnome-panel-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Panel component for the GNOME 2 Desktop

RUN_DEPENDS=	gnome-menu-editor:${PORTSDIR}/deskutils/gnome-menu-editor

USE_BZIP2=	yes
INSTALLS_OMF=	yes
INSTALLS_SHLIB=	yes
INSTALLS_ICONS=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop \
		libwnck gnomemenus gnomedocutils ltverhack
WANT_GNOME=	yes
GNOME_DESKTOP_VERSION=2
USE_GMAKE=	yes
USE_AUTOTOOLS=  libtool:15
CONFIGURE_ARGS=	--with-kde-datadir=${LOCALBASE}/share \
		--with-kde-docdir=${LOCALBASE}/share/doc
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnome-panel.1
GCONF_SCHEMAS=	clock.schemas fish.schemas \
		panel-compatibility.schemas panel-general.schemas \
		panel-global.schemas panel-object.schemas \
		panel-toplevel.schemas window-list.schemas \
		workspace-switcher.schemas

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
.undef WITHOUT_GNOME
WITH_GNOME=	yes
.endif

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mevolutiondataserver}!=""
USE_GNOME+=	evolutiondataserver
CONFIGURE_ARGS+=--enable-eds
.else
CONFIGURE_ARGS+=--disable-eds
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|evolution.desktop|evolution-2.4.desktop|g' \
		${WRKSRC}/gnome-panel/panel-default-setup.entries.in
.if ( ${OSVERSION} > 600000 && ${OSVERSION} < 600006 ) || \
	( ${OSVERSION} < 503101 )
.for po in da.po it.po zh_CN.po zh_TW.po
	@${REINPLACE_CMD} -e 's|%-|%|g' ${WRKSRC}/po/${po}
.endfor
.endif

.include <bsd.port.post.mk>
