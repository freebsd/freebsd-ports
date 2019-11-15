# $FreeBSD$

PORTNAME=	ly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	TUI (ncurses-like) display manager for X and Wayland

LICENSE=	WTFPL
LICENSE_FILE=	${WRKSRC}/license.md

BUILD_DEPENDS=	ginstall:sysutils/coreutils

USES=		gmake localbase xorg
USE_GITHUB=	yes
GH_ACCOUNT=	cylgom
GH_TUPLE=	cylgom:argoat:36c41f09ecc2a10c9acf35e4194e08b6fa10cf45:argoat/sub/argoat \
		cylgom:testoasterror:71620b47872b5535f87c908883576d73153a6911:testoasterror/sub/argoat/sub/testoasterror \
		cylgom:configator:8227b3a835bf4c7e50a57e4ad6aff620ba0dc349:configator/sub/configator \
		cylgom:ctypes:5dd979d3644ab0c85ca14e72b61e6d3d238d432b:ctypes/sub/ctypes \
		cylgom:dragonfail:6b40d1f8b7f6dda9746e688666af623dfbcceb94:dragonfail/sub/dragonfail \
		cylgom:termbox_next:2312da153e44face7bb45aa2798ec284289c17ca:termbox_next/sub/termbox_next
USE_XORG=	xcb

MAKEFILE=	makefile
MAKE_ARGS=	CC="${CC}" \
		DISTVERSIONFULL="${DISTVERSIONFULL}"
ALL_TARGET=	final

BINARY_ALIAS=	install=ginstall

SUB_FILES=	pkg-message

_GITDIR=	${WRKDIR}/${GH_PROJECT}-git

post-patch:
	# Note to maintainers: patches can be regenerated with
	# "make clean extract do-patch makepatch" (YMMV).
	@${REINPLACE_CMD} "s|%%ETCDIR%%|${ETCDIR}|g" ${WRKSRC}/src/config.c
	@${REINPLACE_CMD} -e "s|%%ETCDIR%%|${ETCDIR}|g" \
		-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/res/config.ini
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/res/xsetup.sh

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ly
.for _f in config.ini xsetup.sh wsetup.sh
	@${MV} ${STAGEDIR}${ETCDIR}/${_f} \
		${STAGEDIR}${ETCDIR}/${_f}.sample
.endfor

# Target for maintainers. Use this target to regenerate GH_TUPLE for Git
# submodules used by the project (and project's dependencies).
_git-submodules-to-gh-tuple:
	${RM} -r ${_GITDIR}
	git clone https://github.com/${GH_ACCOUNT}/${GH_PROJECT} ${_GITDIR}
	git -C ${_GITDIR} checkout ${GH_TAGNAME}
	${REINPLACE_CMD} 's/make github/${MAKE_CMD} github/g' ${_GITDIR}/makefile
	${MAKE_CMD} -C ${_GITDIR} github
	git -C ${_GITDIR} submodule status --recursive | cut -c 2- | \
		${AWK} -f ${FILESDIR}/git-submodules-to-gh-tuple.awk

.include <bsd.port.mk>
