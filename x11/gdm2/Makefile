# New ports collection makefile for:   gdm2
# Date created:        20 May 2002
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdm2
PORTVERSION=	2.4.4.7
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=		sources/${PORTNAME:S/2$//}/2.4
DISTNAME=	gdm-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 version of xdm display manager

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack gnomehier libgnomeui librsvg2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GDMDIR?=	${PREFIX}/etc/gdm

MAN1=		gdm.1

.include <bsd.port.pre.mk>

.if exists(/usr/include/security/pam_misc.h)
PLIST_SUB=	PAM_MISC=""
.else
PLIST_SUB=	PAM_MISC="@comment "
.endif

post-extract:
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" \
		${FILESDIR}/gdm.sh.sample > ${WRKSRC}/gdm.sh.sample

post-patch:
.if ${OSVERSION} >= 450002 && ${OSVERSION} < 500000 || ${OSVERSION} >= 500020
	@${REINPLACE_CMD} -E -e 's/(..)\.EUC/\1.euc\1/' ${WRKSRC}/config/locale.alias
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/gdm.sh.sample ${PREFIX}/etc/rc.d
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
